find . -name "*.sh" | cut -c 3- | rev | cut -c 4- | cut -d '/' -f1 | rev
