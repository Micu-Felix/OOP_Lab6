#include "../src/controller/AdministratorController.h"
#include "gtest/gtest.h"
/**
 * TESTS
 */
TEST(AdministratorControllerTest, AddFilm) {
   AdministratorController controller = AdministratorController();

    controller.add_film(Film("Name1", "Type1", 10,10,"xsa1"));

    auto vect= controller.view_filme();
        ASSERT_EQ("Name", vect[0].gettitel());
        ASSERT_EQ("Type", vect[0].getgenre());
        ASSERT_EQ(10, vect[0].getjahr());

}


TEST(AdministratorControllerTest, DeleteFilm) {
    AdministratorController controller = AdministratorController();

    // controller.add_film(Film("Name", "Type", 10,10,"xsa"));

    auto vect= controller.view_filme();
    ASSERT_EQ(controller.delete_film("Name", 10),true);


}

TEST(AdministratorControllerTest, EditFilm) {
    AdministratorController controller = AdministratorController();

    // controller.add_film(Film("Name", "Type", 10,10,"xsa"));

    auto vect= controller.view_filme();
    ASSERT_EQ(controller.edit_film("Name", 10, "http://www.google.ro"),true);


}


TEST(FilmTests, Getters) {

    AdministratorController controller = AdministratorController();
    auto vect= controller.view_filme();
    ASSERT_EQ("Name1", vect[0].gettitel());
    ASSERT_EQ("Type1", vect[0].getgenre());
    ASSERT_EQ(10, vect[0].getjahr());
    ASSERT_EQ(10, vect[0].getlikes());
    ASSERT_EQ("xsa1", vect[0].gettrailer());

}


TEST(FilmTests, Setters) {
    AdministratorController controller = AdministratorController();
    auto vect= controller.view_filme();
    vect[0].settitel("Name2");
    vect[0].setgenre("Type2");
    vect[0].setlikes(12);
    vect[0].setjahr(13);
    vect[0].settrailer("www.google.de");
    ASSERT_EQ("Name2", vect[0].gettitel());
    ASSERT_EQ("Type2", vect[0].getgenre());
    ASSERT_EQ(13, vect[0].getjahr());
    ASSERT_EQ(12, vect[0].getlikes());
    ASSERT_EQ("www.google.de", vect[0].gettrailer());


}


