From Wikipedia: [link](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods).

The most widely known member of the Runge–Kutta family is generally referred to as "RK4", the "classic Runge–Kutta method" or simply as "the Runge–Kutta method".

Let an initial value problem be specified as follows:

$$
\frac{dy}{dt} = f(t,y),\quad y(t_0) = y_0.
$$

Here $y$ is an unknown function (scalar or vector) of time $t$, which we would like to approximate; we are told that $\displaystyle\frac {dy}{dt}$, the rate at which $y$ changes, is a function of $t$ and of $y$ itself. At the initial time $t_{0}$ the corresponding $y$ value is $y_{0}$. The function $f$ and the initial conditions $t_{0}$, $y_{0}$ are given.

Now we pick a step-size $h>0$ and define:

$$
\begin{align}
y_{n+1} &= y_n + \frac{h}{6}(k_1 + 2k_2 + 2k_3 + k_4),\nonumber
\\ t_{n+1} &= t_n + h \nonumber
\end{align}
$$

for $n=0,1,2,3,\cdots$, using

$$
\begin{align}
k_1 &= f(t_n,y_n),\nonumber\\
k_2 &= f\left(t_n + \frac{h}{2}, y_n + k_1\frac{h}{2}\right), \nonumber\\
k_3 &= f\left(t_n + \frac{h}{2}, y_n + k_2\frac{h}{2}\right), \nonumber\\
k_4 &= f(t_n + h, y_n + hk_3) \nonumber
\end{align}
$$

Here $y_{n+1}$ is the RK4 approximation of $y(t_{n+1})$, and the next value $(y_{n+1})$ is determined by the present value $(y_n)$ plus the weighted average of four increments, where each increment is the product of the size of the interval, $h$, and an estimated slope specified by function $f$ on the right-hand side of the differential equation.

* $k_1$ is the slope at the beginning of the interval, using $y$ (Euler's method),
* $k_2$ is the slope at the midpoint of the interval, using $y$ and $k_1$,
* $k_3$ is again the slope at the midpoint, but now using $y$ and $k_2$,
* $k_4$ is the slope at the end of the interval, using $y$ and $k_3$.

In averaging the four slopes, greater weight is given to the slopes at the midpoint. If $f$ is independent of $y$, so that the differential equation is equivalent to a simple integral, then RK4 is Simpson's rule.

The RK4 method is a fourth-order method, meaning that the local truncation error is on the order of $\mathcal{O}(h^5)$, while the total accumulated error is on the order of $\mathcal{O}(h^4)$.

In many practical applications the function $f$ is independent of $t$ (so called autonomous system, or time-invariant system, especially in physics), and their increments are not computed at all and not passed to function $f$, with only the final formula for $t_{n+1}$ used.