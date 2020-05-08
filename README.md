# Arduino Starter w/ Nix?

```
nix-shell --pure
direnv allow
cd blink
direnv allow
upload
```

- Helpful aliases (like "upload") are defined in "shell.nix".

- Makes use of direnv to customize command for each project.
