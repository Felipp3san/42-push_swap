# push_swap

This project is part of the 42 School curriculum, designed to challenge your algorithmic skills and mastery of stacks. The goal of **push_swap** is to sort a set of integers using a limited set of stack operations as efficiently as possible.

## 🚩 Overview

**push_swap** sorts numbers using two stacks (**A** and **B**), following a restricted set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). You must craft the most optimized sequence of moves possible to achieve a sorted stack.

## 🧠 Algorithm & Optimization

For this project, I implemented an optimized **Quick Sort**-based algorithm with several advanced improvements. One of the key optimizations is dividing the stacks further — instead of only using two stacks, the algorithm conceptually splits them, treating the data as if operating over **4 partitions**. This strategy reduces the total number of moves needed dramatically, especially as the datasets get larger.

- **100 numbers**: ~650 moves
- **500 numbers**: ~4500 moves

This approach helped me reach the **maximum grade** in the 42 evaluation!

## 📊 Example

```bash
$ ./push_swap 5 4 3 2 1
sa
ra
sa
rra
pb
...
```

## 🧩 Features

- Handles all input edge cases (duplicates, invalid input, etc.)
- Efficient for large datasets while respecting project constraints
- Well-commented code following 42 norms

## 🎨 Visualizer

During the development of this project, I extensively used the fantastic visualizer by [@o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer).

> **Tip:** I highly recommend trying it — it’s incredibly helpful to see your algorithms in action and debug movement optimizations visually!

## 📦 Usage

```bash
make
./push_swap [numbers...]
```

## 📝 Compilation

```bash
make
```

## 🛠 How it Works

- Parses and validates input numbers
- Applies optimized quick sort, leveraging stack division/partitioning techniques
- Outputs the operation sequence to stdout

## 🥇 Performance & Results

| Dataset Size | Number of Moves |
|--------------|----------------|
| 100          | ~650           |
| 500          | ~4500          |

✔️ Achieved **maximum grade** (full score) at 42 School!

## 🤝 Acknowledgements

- [@o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) for the invaluable visualization tool

---

> *Part of the 42 School common core algorithmic projects — see also: [minishell](https://github.com/Felipp3san/minishell), [pipex](https://github.com/Felipp3san/pipex), [philosophers](https://github.com/Felipp3san/philosophers)...*