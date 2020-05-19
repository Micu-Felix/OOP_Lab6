#include "../src/controller/AdministratorController.h"
#include "gtest/gtest.h"

TEST(ChocolateControllerTest, AddAndFindChocolate) {
   AdministratorController controller = AdministratorController();

    controller.add_film(Film("Name", "Type", 10,10,"xsa"));

    for(Film film : controller.view_filme()) {
        ASSERT_EQ("Name", film.gettitel());
        ASSERT_EQ("Type", film.getgenre());
        ASSERT_EQ(10, film.getjahr());
    }
}