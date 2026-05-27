#include <cassert>
#include <Eigen/Dense>

#include "gradiente_coniugato.hpp"

int main()
{
    const unsigned int n = 4;
    const double tol = 1.0e-12;
    const unsigned int max_it = 10000;

    Eigen::MatrixXd A(n, n);

    A << 4.0, 1.0, 0.0, 0.0,
         1.0, 3.0, 1.0, 0.0,
         0.0, 1.0, 2.0, 1.0,
         0.0, 0.0, 1.0, 2.0;

    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_ex;
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    CGResult result =
        gradiente_coniugato(A, b, x0, tol, max_it);

    const double err_rel =
        (result.x - x_ex).norm() / x_ex.norm();

    assert(err_rel < 1.0e-10);
    assert(result.relative_residual < 1.0e-10);

    return 0;
}