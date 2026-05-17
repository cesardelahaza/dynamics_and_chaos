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

# RK4 Method

In this case, we proceed as before:

We call $\omega = \theta^{(1)}$. Then we write the equations for this. We have

$$
\frac{d\theta}{dt} = f(t,\theta) = \omega(t,\theta),\quad \theta(t_0) = \theta_0
$$

and we write

$$
\begin{align}
\theta_{n+1} &= \theta_n + \frac{h}{6}\left(k_1 + 2k_2 + 2k_3 + k_4\right)\nonumber\\
t_{n+1} &= t_n + h\nonumber\\\nonumber\\\nonumber

k_1^{\theta} &= \omega(t_n,\theta_n),\\\nonumber
k_2^{\theta} &= \omega\left(t_n+\frac{h}{2}, \theta_n + k_1\frac{h}{2}\right), \\\nonumber
k_3^{\theta} &= \omega\left(t_n+\frac{h}{2}, \theta_n + k_2\frac{h}{2}\right), \\\nonumber
k_4^{\theta} &= \omega\left(t_n+h, \theta_n + k_3h\right)
\end{align}
$$

Then, we recall that

$$
\frac{d\omega}{dt} = \frac{d^2\theta}{dt^2} = -\frac{g}{L}\sin\theta(t) = f(t,\omega)
$$

and we write, again:

$$
\begin{align}
\omega_{n+1} &= \omega_n + \frac{h}{6}\left(k_1 + 2k_2 + 2k_3 + k_4\right)\nonumber\\
t_{n+1} &= t_n + h\nonumber\\\nonumber\\\nonumber

k_1^{\omega} &= -\frac{g}{L}\sin\theta(t_n,\omega_n),\\\nonumber
k_2^{\omega} &= -\frac{g}{L}\sin\theta\left(t_n + \frac{h}{2},\omega_n + k_1\frac{h}{2}\right), \\\nonumber
k_3^{\omega} &= -\frac{g}{L}\sin\theta\left(t_n + \frac{h}{2},\omega_n + k_2\frac{h}{2}\right), \\\nonumber
k_4^{\omega} &= -\frac{g}{L}\sin\theta\left(t_n + h,\omega_n + k_3h\right)
\end{align}
$$

In particular, for the first iteration and initial condition:

$$
\begin{align}
\theta_1 &= \theta_0 + \frac{h}{6}\left(k_1^{\theta} + 2k_2^{\theta} + 2k_3^{\theta} + k_4^{\theta}\right),\nonumber\\\nonumber
\omega_1 &= \omega_0 + \frac{h}{6}\left(k_1^{\omega} + 2k_2^{\omega} + 2k_3^{\omega} + k_4^{\omega}\right),
\end{align}
$$

and the $k$'s:

$$
\begin{align}
& k_1^{\theta}(t_0) = \omega(t_0,\theta_0) = \omega_0, & 
k_1^{\omega}(t_0) = -\frac{g}{L}\sin\theta_0, & \nonumber\\\nonumber
& k_2^{\theta}(t_0) = \omega_0+k_1^{\omega}\frac{h}{2}, & 
k_2^{\omega}\left(t_0+\frac{h}{2}\right) = -\frac{g}{L}\sin\left(\theta_0 + k_1^{\theta}\frac{h}{2}\right), & \nonumber\\\nonumber
& k_3^{\theta}(t_0) = \omega_0 + k_2^{\omega}\frac{h}{2}, & 
k_3^{\omega}\left(t_0+\frac{h}{2}\right) = -\frac{g}{L}\sin\theta\left(\theta_0 + k_2^{\theta}\frac{h}{2}\right), & \nonumber\\\nonumber
& k_4^{\theta}(t_0) = \omega_0+k_3^{\omega}h, & 
k_4^{\omega}(t_0+h) = -\frac{g}{L}\sin(\theta_0+k_3^{\theta}h).
\end{align}
$$

To sum up, the parameters we need are (in general):

* $t_0$
* $h$
* $\theta_0 = \theta(t_0)$
* $\omega_0=\omega(t_0)$