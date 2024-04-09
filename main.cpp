//main

#include <iostream>
#include <string>
#include <limits>
#include "Playlist.h"

using namespace std;

int main() {
    string playlistTitle;
    char choice;
    bool quit = false;
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playlistTitle);

    Playlist playlist;
    playlist.head = nullptr;
    playlist.tail = nullptr;
    //loop until user quits
    while (!quit) {
        playlist.PrintMenu(playlistTitle);
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //quit
        if (choice == 'q') {
            quit = true;
        }
        //output full playlist
        else if (choice == 'o') {
            playlist.OutputPlaylist(playlistTitle);
        }
        //add song
        else if (choice == 'a') {
            playlist.AddSong();
        }
        //remove song
        else if (choice == 'd') {
            playlist.RemoveSong();
        }
        //change position of song
        else if (choice == 'c') {
            playlist.ChangeSongPosition();
        }
        //output songs by specific artist
        else if (choice == 's') {
            playlist.OutputSongsByArtist();
        }
        //output total time of playlist
        else if (choice == 't') {
            playlist.OutputTotalTime();
        }
    }


    return 0;
}