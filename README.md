# UIC CS 402 Fall 2026
GitHub repository for projects and any other code used/needed for the class. The assignments/other code in this repository are separated using git branches.

## How to use this repository
1. Fork or clone this repository. You will need to add this repository to your GitHub for version control and submission of projects. You have 2 options for this.
    - **Fork the repository.** While logged into GitHub, navigate to the repository and simply fork it to your own GitHub.
    - **Clone the repository.** Alternatively, you can clone this repository to your local machine, then create a new GitHub repository and add your local repository to the created GitHub repo.
2. Have the repository on your local machine. If you fork the repository, you simply need to clone the repo to your local machine. If you first cloned the repo then uploaded it to GitHub, you already have it on your local machine.
3. Fetch changes. Run the command `git fetch` to ensure you have all the changes from this repository, including new branches.
4. Switch to the appropriate branch. This repository will separate projects, in-class code, etc., using git branches to keep things separate. Once you have cloned the repository, you can switch branches to the appropriate project/assignment/etc., and get started working. To see which branches are available, run the command `git branch -v -a`. Then, to switch branches, run `git switch <branch_name>`, where `<branch_name>` is the name of the branch you want to switch to.

## Example Usage
Let us say you are going to work on `project-1`. Follow these steps.
1. Fork/clone the repository.
2. Clone the repository to your local machine.
3. Enter the cloned repository, then run the command `git fetch`.
3. In the repository, switch branches. Using the command line, this can be done by invoking the command `git branch -v a` to make sure `project-1` is a branch, then by running the command `git switch project-1`.
4. You can now track all of your changes to your `project-1` using this branch.

## Syncing with this Repository on GitHub
1. If you have forked the repository on GitHub, go to your version of the repository (under your GitHub account).
Near the top of the repository, there should be a `Sync fork` option, which will allow you to sync your fork with updates I have pushed to the main repository.
Note you may have to handle merge conflicts, but I have tried to streamline the process to avoid this whenever possible (though conflicts are still possible!).

2. If you cloned the repository and put it in your own GitHub, then you will need to add the original repository as another remote repository.
Here are the steps.
    a. In your repository for the course projects, execute the command `git remote add upstream https://github.com/arblock-uic/uic-cs-402-fall-2026` (or if you are accessing GitHub using SSH keys, execute `git remote add upstream git@github.com:arblock-uic/uic-cs-402-fall-2026.git`).
    This will specify a new remote repository named `upstream`, pointing to my repository.
    b. To sync changes with this repository, execute `git pull upstream <branch>`.
    For example, `git pull upstream main` pulls changes from the main branch, `git pull upstream project-2` pulls changes from the project-2 branch, etc.

