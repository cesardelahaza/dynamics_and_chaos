# Pendulum system

In the absence of damping and external driving, the motion of a pendulum is governed by

$$\frac{d^2\theta}{dt^2} + \frac{g}{L}\sin\theta = 0$$

where $\theta$ is the angle from the downward vertical, $g$ is the acceleration due to gravity, and $L$ is the length of the pendulum.

# Euler Method

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

With this, for any step:

$$
\omega(t + h) = h\cdot\left(-\frac{g}{L}\sin\theta(t)\right) + \omega(t) 
$$

And

$$
\theta(t + h) = h\cdot \omega(t) + \theta(t)
$$

These are the two equations we need and we need the initial conditions we wrote before. Let's write them again with the new notation:

* $t_0$
* $h$
* $\theta(t_0)$
* $\omega(t_0)$

Particularly, for the first step, we have:

$$
\omega(t_0 + h) = h\cdot\left(-\frac{g}{L}\sin\theta(t_0)\right) + \omega(t_0)
$$

And

$$
\theta(t_0 + h) = h\cdot \omega(t_0) + \theta(t_0)
$$