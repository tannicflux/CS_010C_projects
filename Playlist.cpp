//Playlist.cpp

#include "Playlist.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;



// Default constructor
PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

// Parameterized constructor
PlaylistNode::PlaylistNode(const string& id, const string& song, const string& artist, int length)
        : uniqueID(id), songName(song), artistName(artist), songLength(length), nextNodePtr(nullptr) {}

// Destructor
PlaylistNode::~PlaylistNode() {}

//Copy constructor

PlaylistNode::PlaylistNode(const PlaylistNode &node) {
    uniqueID = node.uniqueID;
    songName = node.songName;
    artistName = node.artistName;
    songLength = node.songLength;
    nextNodePtr = nullptr;
}

//insert a node after the current node
void PlaylistNode::InsertAfter(PlaylistNode* node) {
    PlaylistNode* temp = this->nextNodePtr;
    this->nextNodePtr = node;
    node->nextNodePtr = temp;
}

void PlaylistNode::SetNext(PlaylistNode* node) {
    nextNodePtr = node;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

//Destructor

Playlist::~Playlist() {
    PlaylistNode* current = head;
    PlaylistNode* next = nullptr;
    //loop through the playlist to delete each node
    while (current != nullptr) {
        next = current->GetNext();
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

//Copy constructor
Playlist::Playlist(const Playlist& source) {
    head = nullptr;
    tail = nullptr;
    PlaylistNode* sourceNode = source.head;
    //loop through the source playlist to copy each node
    while (sourceNode != nullptr) {
        PlaylistNode* newNode = new PlaylistNode(*sourceNode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->SetNext(newNode);
            tail = newNode;
        }
        sourceNode = sourceNode->GetNext();
    }
}

void Playlist::PrintMenu(const string &title) const {
    cout << title << " PLAYLIST MENU\n";
    cout << "a - Add song\n";
    cout << "d - Remove song\n";
    cout << "c - Change position of song\n";
    cout << "s - Output songs by specific artist\n";
    cout << "t - Output total time of playlist (in seconds)\n";
    cout << "o - Output full playlist\n";
    cout << "q - Quit\n\n";
    cout << "Choose an option:" << endl;
}

void Playlist::OutputPlaylist(const string &title) const{
    int count = 1;
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
    if (head == nullptr) {
        cout << "Playlist is empty" << endl << endl;
    }
    else {
        PlaylistNode* current = head;
        //loop through the playlist
        while (current != nullptr) {
            cout << count << "." << endl;
            current->PrintPlaylistNode();
            cout << endl;
            current = current->GetNext();
            count++;
        }
    }

}

void Playlist::AddSong() {
    string uniqueId, songName, artistName;
    int songLength;
    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:" << endl;
    cin >> uniqueId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter song's name:" << endl;
    getline(cin, songName);
    cout << "Enter artist's name:" << endl;
    getline(cin, artistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> songLength;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    PlaylistNode *newSong = new PlaylistNode(uniqueId, songName, artistName, songLength);
    if (head == nullptr) { //if playlist is empty
        head = newSong;
        tail = newSong;
    }
        //if playlist is not empty
    else {
        tail->InsertAfter(newSong);
        tail = newSong;
    }
}

void Playlist::RemoveSong() {
    string uniqueId, songName;
    cout << "REMOVE SONG\n";
    cout << "Enter song's unique ID:";
    cin >> uniqueId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
    PlaylistNode* current = head;
    PlaylistNode* previous = nullptr;
    //loop through the playlist to find the song
    while (current != nullptr) {
        //if the song is found in the playlist
        if (current->GetID() == uniqueId) {
            //if the song is the first song in the playlist
            if (current == head) {
                head = current->GetNext();
                songName = current->GetSongName();
                delete current;
            }
            //if the song is the last song in the playlist
            else if (current->GetNext() == nullptr) {
                PlaylistNode* previous = head;
                //loop through the playlist to find the previous song
                while (previous->GetNext() != current) {
                    previous = previous->GetNext();
                }
                previous->SetNext(nullptr);
                songName = current->GetSongName();
                delete current;
            }
            //if the song is in the middle of the playlist
            else {
                previous->SetNext(current->GetNext());
                songName = current->GetSongName();
                delete current;
            }
        }
        previous = current;
        current = current->GetNext();
    }
    cout << "\"" << songName << "\" removed." << endl << endl;
}

void Playlist::ChangeSongPosition() {
    string songName;
    int currentPos, newPos;
    cout << "CHANGE POSITION OF SONG\n";
    cout << "Enter song's current position:" << endl;
    if(!cin >> currentPos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        runtime_error("Invalid position");
        return;
    }
    cout << "Enter new position for song:" << endl;
    if(!cin >> newPos) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        runtime_error("Invalid position");
        return;
    }
    // if the current position is the same as the new position or the playlist is empty
    if (currentPos == newPos || head == nullptr) {
        return;
    }

    PlaylistNode* current = head;
    PlaylistNode* previous = nullptr;
    PlaylistNode* nodeToMove = nullptr;
    PlaylistNode* prevNodeToMove = nullptr;
    int count = 1;

    // Find the node at the current position and its previous node
    while (current != nullptr && count <= currentPos) {
        // If the current position is found
        if (count == currentPos) {
            nodeToMove = current;
            prevNodeToMove = previous;
            break;
        }
        previous = current;
        current = current->GetNext();
        count++;
    }

    // Check if the current position is valid
    if (nodeToMove == nullptr) {
        cout << "Invalid current position";
    }

    // Remove the node from its current position
    if (nodeToMove == head) {
        head = nodeToMove->GetNext();
    }
    else {
        prevNodeToMove->SetNext(nodeToMove->GetNext());
    }

    if (nodeToMove == tail) {
        tail = prevNodeToMove;
    }

    // Insert the node at the new position
    if (newPos <= 1) {
        nodeToMove->SetNext(head);
        head = nodeToMove;
    }
    else {
        current = head;
        previous = nullptr;
        count = 1;

        // Find the node at the new position and its previous node
        while (current != nullptr && count < newPos) {
            previous = current;
            current = current->GetNext();
            count++;
        }

        // Insert the node at the new position
        if (current == nullptr) {
            previous->SetNext(nodeToMove);
            nodeToMove->SetNext(nullptr);
            tail = nodeToMove;
        }
        else {
            nodeToMove->SetNext(current);
            previous->SetNext(nodeToMove);
        }
    }

    cout << "\"" << nodeToMove->GetSongName() << "\" moved to position " << newPos << endl << endl;
}

void Playlist::OutputSongsByArtist() const {
    string artist;
    cout << "output songs by artist" << endl;
    cout << "Enter artist's name:\n\n";
    getline(cin, artist);
    int count = 1;
    PlaylistNode* current = head;
    //loop through the playlist to find songs by the artist
    while (current != nullptr) {
        if (current->GetArtistName() == artist) {
            cout << count << "." << endl;
            current->PrintPlaylistNode();
            cout << endl;
        }
        count++;
        current = current->GetNext();
    }
    if (count == 1) {
        cout << "No songs by " << artist << " in playlist" << endl << endl;
    }
}

void Playlist::OutputTotalTime() const {
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n";
    int totalTime = 0;
    PlaylistNode *current = head;
    while (current != nullptr) {
        totalTime += current->GetSongLength();
        current = current->GetNext();
    }
    cout << "Total time: " << totalTime << " seconds" << endl << endl;
}