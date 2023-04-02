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
    auto song = std::make_shared<Song>("ANSI.SYS", "Master Boot Record"); 

    // Use the shared_ptr for something - same as unique ptr.
    // Note here: song is a pointer to the class
    std::cout << "Listening to " << song->getTitle() << "by" << song->getArtist() << \
    " increases my coding productivity" << std::endl; 

    // Let's have another copy of the same song, because now we can
    std::shared_ptr<Song> song2 = song;

    // Interesting feature: count how many "song" are around
    // Note that we're not using ->  as we are asking an object of type shared_ptr
    std::cout << "Question: How many shared_ptrs own the same (shared) pointer? Answer: " << song2.use_count() << std::endl;
    
    //The nice thing is that you don't have to worry about delete, double-delete...everything is done for you!

}
