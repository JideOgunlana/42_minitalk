# Minitalk
![](https://github.com/JideOgunlana/42_minitalk/blob/main/usage_minitalk.gif)


## Summary
> *Mintalk is a client-server communication program that allows sending and receiving messages using UNIX signals. The server process must be started first and will print its Process ID (PID) upon launch. The client process takes two parameters: the server PID and the string to send*.


## Features
- Server and client components for interprocess communication.
- Server prints its PID upon launch.
- Client sends a string to the server using UNIX signals.
- Server quickly displays the received string (1 second for 100 characters).
- Server can receive messages from multiple clients without needing to restart.
- Communication is achieved using the SIGUSR1 and SIGUSR2 signals.
- Bonus feature: Server acknowledges every message received by sending a signal back to the client.
- Bonus feature: Support for Unicode characters.

## Credits
This project is part of the curriculum at 42, a coding school that fosters peer-to-peer learning and project-based education.