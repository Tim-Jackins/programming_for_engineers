# Programming for Engineers

## Setup

Set up WSL (I used Ubuntu 18) install some packages:

```bash
sudo apt-get update
sudo apt-get install build-essential gdb
```

Setup your vscode configs thusly:

.vscode/c_cpp_properties.json
```json
{
    "configurations": [
        {
            "name": "Linux",
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "${default}",
            "browse": {
                "path": [
                    "${workspaceFolder}"
                ],
                "limitSymbolsToIncludedHeaders": true,
                "databaseFilename": ""
            }
        }
    ],
    "version": 4
}
```

.vscode/launch.json
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "<path to out>/program.out",
            "args": [
                ""
            ],
            "stopAtEntry": true,
            "cwd": "/home/jack/programmingForEngineers/",
            "environment": [],
            "externalConsole": true,
            "windows": {
                "MIMode": "gdb",
                "miDebuggerPath": "/usr/bin/gdb",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ]
            },
            "pipeTransport": {
                "pipeCwd": "",
                "pipeProgram": "c:\\windows\\sysnative\\bash.exe",
                "pipeArgs": [
                    "-c"
                ],
                "debuggerPath": "/usr/bin/gdb"
            },
            "sourceFileMap": {
                "/mnt/c": "${env:systemdrive}/",
                "/usr": "C:\\Users\\timmi\\AppData\\Local\\Packages\\CanonicalGroupLimited.UbuntuonWindows_79rhkp1fndgsc\\LocalState\\rootfs\\usr\\"
            }
        }
    ]
}
```

.vscode\tasks.json
```json
{
    "version": "2.0.0",
    "windows": {
        "options": {
            "shell": {
                "executable": "bash.exe",
                "args": ["-c"]
            }
        }
    },
    "tasks": [
        {
            "label": "build hello world on WSL",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "-o",
                "/home/jack/programmingForEngineers/helloworld.out",
                "helloworld.cpp"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```
