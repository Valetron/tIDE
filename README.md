# c1d3
Console Integrated Development Environment

# Build

## Conan

Release mode
```
conan install -if cmake --build=missing .  
```

Debug mode
```
conan install -if cmake --build=missing -s build_type=Debug .
```

