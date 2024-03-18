// PL10/unique_ptr.cpp
// Example of use of unique_ptr (RAII)
// Caterina Doglioni, last updated 28/03/2023
// Inspired by: https://learn.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-170
// Soundtrack while coding this example provided by: https://masterbootrecord.bandcamp.com 

#include<memory>
#include<string>
#include<vector>
#include<iostream>

class Song 
{
    public :
        Song(const std::string& title, const std::string& artist) 
        {
            setTitle(title);
            setArtist(artist);
        } 

        void setTitle(std::string title) 
        {
            //TODO: add some input checking.........
            m_title=title;
        }

        void setArtist(std::string artist) 
        {
            //TODO: add some input checking.........
            m_artist=artist;
        }


        std::string getTitle() {return m_title;}
        std::string getArtist() {return m_artist;}

    private :
        std::string m_title;
        std::string m_artist;


};

int main ()
{
    // Create a new unique_ptr with a new object inside - RAII so everything is in one line.
    auto song = std::make_unique<Song>("ANSI.SYS", "Master Boot Record"); 

    // Use the unique_ptr for something.
    // Note here: song is a pointer to the class
    std::cout << "Listening to " << song->getTitle() << "by" << song->getArtist() << \
    " increases my coding productivity" << std::endl; 

    // What we can't do: assign raw pointer to another unique_ptr
    // The compiler error is interesting as it talks of a "deleted function"...
    // This is because copy constructor is a "deleted function"
    // See: https://www.ibm.com/docs/en/i/7.3?topic=definitions-deleted-functions-c11
    // std::unique_ptr<Song> song2 = song;

    // What we can do: move raw pointer from one unique_ptr to another.
    std::unique_ptr<Song> song2 = std::move(song); 
    
    //At this point "song" points to nothing! 
    //This shows that you _can_ get segmentation faults with smart pointers...
    //std::cout << "I am still listening to " << song->getTitle() << "by" << song->getArtist() << \
    //" but its pointer has been moved!" << std::endl; 

}
