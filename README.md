# Music Player Implementation Using Doubly Linked List 


![Screen Shot 2024-07-15 at 3 31 19 AM](https://github.com/user-attachments/assets/4d71f97a-b85a-466e-9042-d4c112e08004)

This project involves the development of a basic music player that utilizes a doubly linked list to manage the playlist. The primary goal of using a doubly linked list in this music player is to enhance navigation through the playlist, allowing seamless transitions between tracks both forwards and backwards.

## Key Features

- **Bidirectional Navigation:** Users can easily move to the next or previous track, thanks to the nature of the doubly linked list which stores references to both the next and previous nodes (tracks).
- **Dynamic Playlist Management:** Tracks can be dynamically added to or removed from the playlist. The doubly linked list allows for efficient insertions and deletions at any point in the list.
- **Robust Track Handling:** Each node in the linked list represents a track and holds details such as the track name, artist, and other metadata, facilitating easy access and management of track information.
- **User Interface:** While the backend logic leverages the doubly linked list, the user interface is simple and intuitive, making it easy for users to interact with the player.

## Implementation Details

- The music player is implemented in C++ which provides robust control over data structures and memory management.
- The application uses the SFML (Simple and Fast Multimedia Library) for graphics and window handling, ensuring compatibility and efficiency.
- Extensive error handling ensures the music player operates smoothly under various conditions, such as missing tracks or invalid input.

## Compilation Instructions

To compile the program, use the following command:

```sh
g++ -o myProgram main.cpp -lsfml-graphics -lsfml-window -lsfml-system


