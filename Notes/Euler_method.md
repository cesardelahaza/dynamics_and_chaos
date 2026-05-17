From Wikipedia: [text](https://en.wikipedia.org/wiki/Euler_method)

The Euler method can be derived in a number of ways.

1. Firstly, there is the geometrical description:

    Consider the problem of calculating the shape of an unknown curve which starts at a given point and satisfies a given differential equation. Here, a differential equation can be thought of as a formula by which the slope of the tangent line to the curve can be computed at any point on the curve, once the position of that point has been calculated.

    The idea is that while the curve is initially unknown, its starting point, which we denote by $A_{0}$, is known. Then, from the differential equation, the slope to the curve at $A_{0}$ can be computed, and so, the tangent line.

    Take a small step along that tangent line up to a point $A_{1}$. Along this small step, the slope does not change too much, so $A_{1}$ will be close to the curve. If we pretend that $A_{1}$ is still on the curve, the same reasoning as for the point $A_{0}$ above can be used. After several steps, a polygonal curve $(A_{0},A_{1},A_{2},A_{3},\dots)$ is computed. In general, this curve does not diverge too far from the original unknown curve, and the error between the two curves can be made small if the step size is small enough and the interval of computation is finite.

2. Another possibility is to consider the Taylor expansion of the function $y$ around $t_0$:
    $$y(t_0+h) = y(t_0) + hy'(t_0) + \frac{1}{2}h^2y''(t_0) + \mathcal{O}(h^3)$$

    The differential equation states that $y'=f(t,y)$. If this is substituted in the Taylor expansion and the quadratic and higher-order terms are ignored, the Euler method arises.

    The Taylor expansion is used below to analyze the error committed by the Euler method, and it can be extended to produce Runge–Kutta methods.

3. A closely related derivation is to substitute the forward finite difference formula for the derivative,

    $$y'(t_0) \approx \frac{y(t_0+h) - y(t_0)}{h}$$

    in the differential equation $y'=f(t,y)$. Again, this yields the Euler method. A similar computation leads to the midpoint method and the backward Euler method.

4. Finally, one can integrate the differential equation from $t_{0}$ to $t_{0}+h$ and apply the fundamental theorem of calculus to get:

    $$y(t_0+h) - y(t_0) = \int_{t_0}^{t_0+h} f(t, y(t)) dt$$

    Now approximate the integral by the left-hand rectangle method (with only one rectangle):

    $$\int_{t_0}^{t_0+h} f(t, y(t)) dt \approx hf(t_0, y(t_0))$$

    Combining both equations, one finds again the Euler method.

-------------

#### Equation and particularization

In the absence of damping and external driving, the motion of a pendulum is governed by

$$\frac{d^2\theta}{dt^2} + \frac{g}{L}\sin\theta = 0$$

where $\theta$ is the angle from the downward vertical, $g$ is the acceleration due to gravity, and $L$ is the length of the pendulum.

In this case, we have a higher-order process in the Euler method because we have a relation of the form

$$\theta^{(2)}(t) = -\frac{g}{L}\sin\theta$$

In order to solve this, we may need some information like:

* $t_0$
* $h$ (the step size)
* $\theta_0=\theta(t_0)$
* $\theta^{(1)}_0 = \theta^{(1)}(t_0)$

Taking into consideration that we have a second-order derivative, this process needs to be processed correctly: we call $\omega=\theta^{(1)}$. With this we have:

$$
\frac{\theta(t_0+h) - \theta(t_0)}{h} \approx \omega(t_0)
$$

and 

$$\frac{\omega(t+h) - \omega(t)}{h}\approx \omega^{(1)}(t) = -\frac{g}{L}\sin\theta(t)$$

With this, for the first step:

$$
\omega(t_0 + h) = h\cdot\left(-\frac{g}{L}\sin\theta(t_0)\right) + \omega(t_0) 
$$

And

$$
\theta(t_0 + h) = h\cdot \omega(t_0) + \theta(t_0)
$$

These are the two equations we need and we need the initial conditions we wrote before. Let's write them again with the new notation:

* $t_0$
* $h$
* $\theta(t_0)$
* $\omega(t_0)$