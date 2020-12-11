# otm
Open-source termux malware!
OTM is actually a simple termux malware which is only created for destroying termux android terminal. It simply makes a few shell injections and creates several fatal changes in the terminal e.g. changing the background-foreground-font colors, changing the default shell to a modified one, customizing speed typing buttons, changing motd etc. Consequently, the application gets frozen and unusable. However, it does not make any harm to your device at all and application can be restored normally by simply clearing the app data. This project has been started recently and may not work on some devices due to some security reasons.
support.c is the main payload file and fbhack.c is made for social engineering purpose. 
