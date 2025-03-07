import numpy as np

def get_next_state(i, j, a):
    if a == 0:
        return (i - 1, j) if (i-1, j) != (1, 1) else (i, j)
    elif a == 1:
        return (i, j + 1) if (i, j+1) != (1, 1) else (i, j)
    elif a == 2:
        return (i + 1, j) if (i+1, j) != (1, 1) else (i, j)
    elif a == 3:
        return (i, j - 1) if (i, j-1) != (1, 1) else (i, j)
    else:
        raise ValueError("Invalid action")
    
def get_reward(s):
    i, j = s
    if i < 0 or i >= 3 or j < 0 or j >= 4:
        return 0
    if i == 2 and j == 3:
        return 1
    if i == 1 and j == 3:
        return -1
    
    r_alive = 0.01
    return r_alive

def get_max_value(Q, s):
    i, j = s
    if i < 0 or i >= 3 or j < 0 or j >= 4:
        return 0
    return np.max(Q[i, j, :])

def main():
    Q = np.zeros((3, 4, 4,))
    print(Q)
    n_epoch = 10
    gamma = 0.9

    for k in range(n_epoch):
        print(f"Epoch {k+1}")
        oldQ = Q.copy()

        for i in range(3):
            for j in range(4):
                for a in range(4):
                    # E_s * [r + gamma * Q_k-1[s',a']]
                    s_prime_main = get_next_state(i, j, a)
                    s_prime_left = get_next_state(i, j, (a+3)%4)
                    s_prime_right = get_next_state(i, j, (a+1)%4)
                    r_main = get_reward(s_prime_main)
                    r_left = get_reward(s_prime_left)
                    r_right = get_reward(s_prime_right)
                    value = 0.8 * (r_main + gamma * get_max_value(oldQ, s_prime_main))
                    value += 0.1 * (r_left + gamma * get_max_value(oldQ, s_prime_left))
                    value += 0.1 * (r_right + gamma * get_max_value(oldQ, s_prime_right))

                    Q[i, j, a] = value
        print(Q)

if __name__ == "__main__":
    main()