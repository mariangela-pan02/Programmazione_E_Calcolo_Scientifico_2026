#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

#include "gradiente_coniugato.hpp"

double condA(const Eigen::MatrixXd& A)
{
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
    Eigen::VectorXd singularValuesA = svd.singularValues();

    return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main()
{
    const double tol = 1.0e-15;
    const unsigned int n = 4;

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (std::abs(B.determinant()) < tol)
        return -1;

    Eigen::MatrixXd A = B.transpose() * B;

    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    const unsigned int max_it = 10000;
    const double res_tol = 1.0e-12;

    CGResult result =
        gradiente_coniugato(A, b, x0, res_tol, max_it);

    const double err_rel =
        (result.x - x_ex).norm() / x_ex.norm();

    std::cout.precision(2);
    std::cout << std::scientific
              << "Matrix Cond: " << condA(A) << std::endl;

    std::cout.precision(4);
    std::cout << std::scientific;

    std::cout << "it/it_max" << std::endl;
    std::cout << result.iterations << "/" << max_it << std::endl;

    std::cout << "res/res_tol" << std::endl;
    std::cout << result.relative_residual << "/" << res_tol << std::endl;

    std::cout << "err_rel" << std::endl;
    std::cout << err_rel << std::endl;

    std::cout << "soluzione" << std::endl;
    std::cout << result.x << std::endl;

    return 0;
}