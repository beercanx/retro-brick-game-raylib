# XServer configuration for Windows

Basically `config.xlaunch` is a quick helper file for launching an xserver on Windows, what it does is allow connections from any IP and this is needed for WSL 2 as the request is technically come via a different system over the network.

This is all before "Support for Linux GUI apps" becomes GA and not part of the Windows Insiders Program. https://docs.microsoft.com/en-us/windows/wsl/tutorials/gui-apps#install-support-for-linux-gui-apps

The xserver in question can be installed via:
```powershell
choco install vcxsrv
```

The display port also has to be setup in the WSL 2 environment
```
# We need the IP of the Windows host as seen by the WSL 2 system.
export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
```