# Git

## 远程仓库信息
``` sh
git remote show origin
```

## 变更
``` sh
# 未暂存变更
git diff filename

# 已暂存变更
git diff --cached filename

# 变更统计
git diff --stat

# 使用vimdiff
git difftool --tool=vimdiff --no-prompt

# 撤销commit
git reset --hard <commit_id>
git push origin HEAD --force
```

## 分支

### 远程分支
``` sh
# 跟踪分支
git checkout -b develop origin/develop

# 设置跟踪
git branch --set-upstream develop origin/develop
```

## 设置
``` sh
# 用户信息
git config --global user.name fasionchan
git config --global user.email fasionchan@gmail.com

# 工具设置
git config --global diff.tool vimdiff
git config --global merge.tool vimdiff
git config --global difftool.prompt false
```

## 杂项

### 忽略修改
``` sh
git checkout -- <file>
git checkout <branch> <file>
```
