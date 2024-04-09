#ifndef CS010C_LAB1_PLAYLIST_H
#define CS010C_LAB1_PLAYLIST_H

#include <string>

using namespace std;

class PlaylistNode {
public:
    // Default constructor
    PlaylistNode();

    // Parameterized constructor
    PlaylistNode(const string& id, const string& song, const string& artist, int length);

    // Destructor
    ~PlaylistNode();

    // Copy constructor
    PlaylistNode(const PlaylistNode &node);

    // Public member functions
    void InsertAfter(PlaylistNode* node);
    void SetNext(PlaylistNode* node);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode() const;
    void PrintAllNodes();

private:
    // Private data members
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
};

class Playlist {
public:
    PlaylistNode* head;
    PlaylistNode* tail;

    // Default constructor
    Playlist(): head(nullptr), tail(nullptr) {}

    // Destructor
    ~Playlist();

    // Copy constructor
    Playlist(const Playlist &playlist);

    // Public member functions
    void PrintMenu(const string&) const;
    void OutputPlaylist(const string&) const;
    void AddSong();
    void RemoveSong();
    void ChangeSongPosition();
    void OutputSongsByArtist() const;
    void OutputTotalTime() const;

};

#endif //CS010C_LAB1_PLAYLIST_H