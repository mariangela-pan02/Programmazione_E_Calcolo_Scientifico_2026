#pragma once

#include <Eigen/Dense>

struct CGResult
{
    Eigen::VectorXd x;
    unsigned int iterations;
    double relative_residual;
};

inline CGResult gradiente_coniugato(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    const Eigen::VectorXd& x0,
    double tol,
    unsigned int max_it
)
{
    Eigen::VectorXd x = x0;

    Eigen::VectorXd r = b - A * x;

    Eigen::VectorXd p = r;

    const double r0_norm = r.norm();

    unsigned int it = 0;

    while (it < max_it &&
           r.norm() > tol * r0_norm)
    {
        const Eigen::VectorXd Ap = A * p;

        const double alpha =
            p.dot(r) / p.dot(Ap);

        x = x + alpha * p;

        Eigen::VectorXd r_new =
            r - alpha * Ap;

        const double beta =
            p.dot(A * r_new) / p.dot(Ap);

        p = r_new - beta * p;

        r = r_new;

        ++it;
    }

    return {x, it, r.norm() / r0_norm};
}