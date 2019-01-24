---
title: cloneBranchFromOrigin
date: 2016-12-14 09:56:49
tags: git 版本管理
---
# 利用git从远程仓库中clone其他分支
## 使用需求说明
- 使用git clone时会默认下载master分支并且实现跟踪，或者可以直接指定要下载的分支。 
- 其他人将其他分支推送到远程之后需要在本地创建一个跟踪分支进行开发。
## 使用方式
1. `git checkout -b branchname origin/branchname`本地创建一个对应的分支。
2. `git checkout -t origin/branchname`直接在本地创建
3. `git fetch origin branchname:branchname`
4. **错误方式:**
   `git branch branchname;git checkout branchname;git pull origin branchname:branchname
    这样是在当前分支上创建新分支再与远程分支合并。
