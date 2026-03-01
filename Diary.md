# GIT

### Connecting to GitHub

1. Create new repository on GitHub: empty, no readme, no .gitignore.
2. In my local repo:
    ```bash
    git init
    ````
3. Create any file.
4. First commit (before doing anything with the branches)
    ```bash
    git add .
    git commit -m "First commit"
    ````
5. Set the branch name
    ```bash
    git branch -M main
    ````
6. Connect my local repo to GitHub:
    ```bash
    git remote add origin https://github.com/cesardelahaza/dynamics_and_chaos.git
    ```
7. Upload the commit
    ```bash
    git push -u origin main
    ```
8. Add .gitignore
    ```bash
    echo build/ >> .gitignore
    git add .gitignore
    git commit -m "Add gitignore"
    git push -u origin main
    ```

### GitHub Projects

1. GitHub $\rightarrow$ Projects $\rightarrow$ New Project $\rightarrow$ Board.
2. Three columns will be set: *Todo*, *In Progress* and *Done*
3. Create first ticket.

### Commits and tickets

Each ticket will have a reference number like #n. So the moment you commit just add which is the number of the ticket that commit is based on.

There are a few helpful words:
* close
* closes
* fixed
* fixes
* resolve
* resolves

### Branches

To change to any branch:

```Bash
# Pull the remote references without altering local branches
git fetch origin

# We switch to the local branch we want to
git checkout -t origin/1-start-pendulum-animation
```

To delete any branch:

```bash
git branch -d name_of_the_undesired_branch
```

### Finish implementation (ticket) in branch and merging data

1. Make sure your branch is updated
    ```bash
    git status
    git add .
    git commit -m "Name of implementation, close #n"
    ```

2. Go back to main
    ```bash
    git checkout main
    git pull origin main
    ```

3. Merge your branch in main
    ```bash
    git merge name_of_branch
    ```
    If there are conflicts, resolve them. Then:
    ```bash
    git add .
    git commit
    ```

4. Upload main to GitHub
    ```bash
    git push origin main
    ````

5. Optional. Delete the branch
    ```bash
    git branch -d name-of-branch
    git push origin --delete name-of-branch
    ```


# SFML

### SFML Homebrew Setup

1. Install Homebrew
2. Install SFML: brew install sfml

### Execute scripts via Bash

1. Create a .sh file in order to execute the $\texttt{main.cpp}$ file.
2. Make it executable: $\texttt{chmod +x build.sh}$.
3. Compile: $\texttt{./build.sh}$.

# Basics

## Pendulum

$\texttt{pendulum.cpp}$

