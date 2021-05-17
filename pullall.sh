git branch --format='%(refname:short)' | xargs -I {} sh -c 'git checkout {}; git pull'
