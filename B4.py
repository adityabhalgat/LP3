
import matplotlib.pyplot as plt

# Objective function
def f(x):
    return (x + 3) ** 2

# Derivative of the function
def df(x):
    return 2 * (x + 3)

# Initial values
x = 5
learning_rate = 0.1
iterations = 20

values = []

# Gradient Descent
for i in range(iterations):

    gradient = df(x)

    # Update x in the opposite direction of gradient
    x = x - learning_rate * gradient

    values.append(f(x))

    print(f"Iteration {i+1}: x = {x:.4f}, f(x) = {f(x):.4f}")

print("\nMinimum value of x:", x)

# Plot convergence
plt.plot(values, marker='o')
plt.xlabel("Iterations")
plt.ylabel("Function Value")
plt.title("Gradient Descent")
plt.grid()
plt.show()
