// PL9/cardboard_box_simulator.cpp
// Define a class template representing a box that can hold a cat or a dog
// Demonstrate friend function with templates
// Caterina Doglioni, Last modified 17/03/2022
#include<iostream>
#include<vector>
using std::vector;

//friend class and function pre-declaration 
template<typename c_type> class cardboard_box;  
template<typename c_type> void remove_from_box(cardboard_box<c_type> theBox);

template <class c_type> class cardboard_box {
private:
  vector<c_type> box_content;
public:
  cardboard_box() : box_content{} {}
  cardboard_box(c_type content) { box_content.push_back(content); }
  
  //this function is there to show something we cannot do
  void kick_out_and_jump_in(c_type kicker) 
  {
    std::cout << "The content of the box is getting replaced!" << std::endl;
    //good practice: before asking for something in a specific place of a vector, check if that is there
    if (box_content.size() > 0) {
        std::cout << "Box content says: '" << box_content[0].upset() << "'" << std::endl;
        box_content.pop_back();
        box_content.push_back(kicker);    
    }
    else {
        std::cout << "Box is empty, nothing to kick out." << std::endl;
        box_content.push_back(kicker);    
    }
 
    return;
  }

  void poke() 
  {
    std::cout << "Poking content of the box." << std::endl;
    //good practice: before asking for something in a specific place of a vector, check if that is there
    if (box_content.size() > 0) {
        std::cout << "Box content says: '" << box_content[0].touch() << "'" << std::endl;
    }
    else std::cout << "Box is empty" << std::endl;
  }

  void pet_content() 
  {
    std::cout << "Petting content of the box." << std::endl;
    std::cout << "Box content says: '" << box_content[0].make_happy() << "'" << std::endl;
  }

  //the friend function, when human intervention is needed
  friend void remove_from_box <> (cardboard_box<c_type> theBox);

};

//when human intervention is needed
template <class c_type >
void remove_from_box(cardboard_box<c_type> theBox) {
    std::cout << "Removing content from the box." << std::endl;
    theBox.box_content.pop_back();
}


// all functions inline because they are one-liners
class cat {

     private :
         std::string name{"Bob"};
     public :
        cat(std::string cat_name){name=cat_name;}
        std::string touch() { return "Meow";}
        std::string upset() { return "Hiss!!!!!!!!!!!!!!"; }
        std::string make_happy() { return "Purr"; }

};

class dog {

     private :
         std::string name{"Ollie"};
     public :
        dog(std::string dog_name){name=dog_name;}
        std::string touch() { return "Woof"; }
        std::string upset() { return "Bark!!!!!!!!!!!!!!"; }
        std::string make_happy() { return "Yip yip"; }

};


int main()
 {

   cat bob_the_cat("Bob");
   cardboard_box<cat> the_cardboard_box(bob_the_cat);
   the_cardboard_box.poke();
   the_cardboard_box.pet_content();

   dog ollie_the_dog("Ollie");
   cardboard_box<dog> the_other_cardboard_box(ollie_the_dog);
   the_other_cardboard_box.poke();
   the_other_cardboard_box.pet_content();

   //this doesn't work! we have made a cardboard box for cats only
   //if we wanted to do this, we should have used polymorphism
   //the_cardboard_box.kick_out_and_jump_in(ollie_the_dog);

   //showing the use of friends
   remove_from_box(the_other_cardboard_box);


   return 0;
}
