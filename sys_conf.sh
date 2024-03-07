#Write shell script to show various system configuration like
#Your current shell
#Your home directory
#Your current working directory


echo "Current user: $USER"
echo "Login name: $LOGNAME"
echo "Current shell: $SHELL"
echo "Home directory: $HOME"
echo "OS type: $(uname -o)"
echo "Current working directory: $PWD"
echo "Currently logged users: $(who | wc -l)"
echo "Path: $PATH"

