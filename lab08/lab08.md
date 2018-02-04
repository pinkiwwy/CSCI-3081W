### Lab 8 : Refactoring and Branching

In this lab, you will prepare the iteration1 code for development of iteration2.
You will maintain multiple branches and use Github _issues_ to track necessary
changes and fixes to the code.

John Harwell has put together an informative guide on the use of git and
branching, much of which was used to create this lab. It can be found in
**_git-usage-f17.pdf_** in the class repo under _project_. You might have previously read through the section on commits. New
material on branching has been added to the bottom of the document.

#### Branching Model

In a general git workflow, such as most you will encounter in industry, the
_master_ branch is not the general purpose development branch. Instead a number
of other branches are used to perform development, and only pristine
(i.e. working/release/etc) versions of the code are pushed to _master_.
For this class, we will be using the following branching model, which is inspired by http://nvie.com/posts/a-successful-git-branching-model.

##### Branches

- **Master**: Always contains 100% functional, working code. Push to this branch
only for releases. Anytime someone clones your repository and gets your master branch,
they should *always* get a working version of code (even if it is not the most
up-to-date, which could live on your _devel_ branch). For this class moving forward,
the **Master** branch will be limited to the final submission for each iteration.
This branch always exists in a git repository, so you will never need to create it.

- **devel** or **integration**: This is the main development branch, and also
where all feature branches branch off of or get merged into. You rarely make
changes directly in this branch, unless it is something trivial. For all
consequential development work, a feature branch should be created off of
_devel_ or _integration_ (depending on what you want to call it) to contain
the work. Branch off of _master_ at the start of a project, and never merge
back into it, except for code releases.

**Start preparing your repo by creating the _devel_ branch.**  While in the
directory of your repo:

```
git checkout master
git checkout -b devel
git push --all origin
```

This will push your newly created _devel_ branch to github. The rest of this
document will assume that you named your development branch _devel_.
You can verify that you are on the new branch with:

```
git branch
```

- **Feature Branches**: These are the branches that should contain the actual
development work. They should be named something specific (i.e. not just
feature/phase2, but feature/phase2-widgetA-scaffolding). Keep your commits on
these branches focused on the issue and make relatively few, unless the complexity
of the feature warrants more. Resist the temptation to follow multiple paths and
address multiple issues on a single feature branch. Instead, open an
issue in github to track what you have found/want to do
(See [[*Github Issues][Github Issues]]), and continue on with the work of the
feature branch.

> A "Feature" branch is an umbrella term for many types of modifications to the
code. Other common reasons for creating a branch include refactoring, bug fixes,
formatting, documentation, and general clean-up.

#### Github Issues

It is important to keep a list of items that need attention in the code. Github
provides that mechanism through the use of _Issues_. In this lab, you will
create 3 issues, the associated branches, and refactor your code accordingly.
The first issue is aligning the style of _Position_ in the code with that of
_Color_. This should be a struct in its own file position.h and it should be
included in the csci3081 namespace.

```
Go to the github site for you repo.
Click on the Issues tab.
Click on the "New Issue" button on the upper right.
Provide an appropriate title and description.
Submit new issue.
```

Notice that there is a number associated with the issue. We will use this for
naming the branch created to address the issue of _Position_.

##### Naming The Branch

Use the categories of modification described above as part of the naming of the
branch. Also use the issue number and a short description. As a reminder, here
are the different categories of changes:
- feature - An actual feature (i.e. adding NEW functionality to the code).
- refactor - Refactoring existing code.
- bugfix - Fix a bug that was found in the code.
- style - Updating/fixing code style (i.e. making it Google style compliant, for example).
- doc - Adding/updating documentation for the code.
- chore - Doing miscellaneous grunt work, such as file moving, renaming, etc.

A reasonable name for this issue is _refactor/01-position-as-struct_, but you
might prefer different wording. **The important part** is that it has the issue
number in the title and the name is meaningful.

Now, make a branch for this new issue. **Confirm you are on the devel branch.**

```
git checkout -b refactor/01-position-as-struct
git push --all origin
```

Make the changes necessary to make Position a struct in its own file in the
namespace.

... And now that you are finished, commit those changes **using the issue
number in the commit AND using the full commit message following the guidelines
provided in the git usage pdf.**

> When you use the issue number in the message, Github recognizes and adds the
commit message as a comment to the issue creating a link between the issue
and any related commits and branches.

```
git add *
git commit
... enter into your editor and follow the guidelines
... the first line should be something like
...     refactor(position.h): fix issue #1 position as struct
git push --set-upstream origin refactor/01-position-as-struct
```

If you are satisfied with the results, you now want to merge this branch with
_devel_ (not with _master_). You can do this in 2 ways. If you want to take a
trial run or if someone else is in control of merging branches, you can submit
a _pull request_. This is a request to pull in your position branch into the
devel branch. You can do this from the Github interface under Pull Requests.
Then you can _accept_ the pull request to merge the branches.
**Make sure your pull request is into the _devel_ branch - select from the
pulldown menus.** Instead, let's do this with the command line.

```
git checkout devel
git merge --no-ff refactor/01-position-as-struct
```

The _--no-ff_ option tells git not to do a fast forward merge, and actually
create a merge object, which is just a technical way of saying making it easier
to roll back changes that break things.

> *Always* branch off of _devel_, and *always* merge back into it.

You can now close the issue through github (notice the commit added to the issue).
And you
don't want those branches polluting your workspace, so let's delete the branch.

```
git branch -d refactor/01-position-as-struct
```

If you need to delete it from github as well, you can do:

```
git push origin :refactor/01-position-as-struct
```

Note the _:_ in the code above -- it will not work without it.


#### Lab Assignment

These are the requirements of this lab:

- Create a branch _devel_
- Create an issue related to the struct Position
- Create a branch for Position
- refactor Position
- Merge the refactoring branch into devel
- Delete the refactoring branch

Repeat the issue/branching for these 2 issues (except don't delete those branches
yet, so that we can see what you are doing):

- Refactor all setters and getters in the arena entities to use the format
"set_" and "get_", for example set_angle and get_angle.

- Fix any mismatch of types for angles and positions, both of which should be
doubles. Cast into int when needed as an integer. While you are looking at types,
make sure that heading, which is expressed in degrees for the robot, is
translated to radians in the graphics drawing functions.
