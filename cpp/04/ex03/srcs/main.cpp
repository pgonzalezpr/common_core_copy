#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
    {
        MateriaSource* src = new MateriaSource();

        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;

        std::cout << "=========================================" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "1. Creating MateriaSource" << std::endl; 
            IMateriaSource* src = new MateriaSource();
            std::cout << std::endl;
            src->printMaterias();
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "2. \"src\" learning 5 materias" << std::endl;
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            
            std::cout << std::endl;
            Ice	*mat = new Ice();
            src->learnMateria(mat);
            delete	mat;

            // std::cout << std::endl;
            src->printMaterias();
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "3. Creating Character \"Jinx\" and \"Vayne\"" << std::endl;
            Character* jinx = new Character("Jinx");
            jinx->printMaterias();
            std::cout << std::endl;

            Character* vayne = new Character("Vayne");
            vayne->printMaterias();
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "4. \"Jinx\" trying to equip 5 materias and \"Vayne\" one materia" << std::endl;
            jinx->equip(NULL);
            

            jinx->equip(src->createMateria("ice"));
            jinx->equip(src->createMateria("ice"));
            jinx->equip(src->createMateria("cure"));
            jinx->equip(src->createMateria("cure"));
            jinx->equip(src->createMateria("cure"));

            std::cout << std::endl;
            jinx->printMaterias();

            std::cout << std::endl;
            vayne->equip(src->createMateria("ice"));
            vayne->printMaterias();
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "5. Testing Character Assignation overload \"jinx = vayne\" for deep copy and changed jinx afterwards" << std::endl;	
            *vayne = *jinx;
            
            jinx->unequip(0);
            std::cout << "JINX" << std::endl;
            jinx->printMaterias();
            std::cout << std::endl;

            std::cout << "VAYNE" << std::endl;
            vayne->setName("Vayne");
            vayne->printMaterias();
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "6. Testing character copy constructor for deep copy \"braum = Character(jinx)\" and changed jinx afterwards" << std::endl;
            
            jinx->printMaterias();
            Character* braum = new Character(*jinx);
            braum->setName("Braum");
            braum->printMaterias();

            jinx->equip(src->createMateria("ice"));
            std::cout << "JINX" << std::endl;
            jinx->printMaterias();
            std::cout << std::endl;

            std::cout << "BRAUM" << std::endl;
            braum->printMaterias();


        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //
        
        std::cout << "7. \"jinx\" using all equiped materias on \"vayne\" " << std::endl;
            jinx->use(0, *vayne);
            jinx->use(1, *vayne);
            jinx->use(2, *vayne);
            jinx->use(3, *vayne);
            jinx->use(10, *vayne);
            jinx->use(-1, *vayne);
        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "8. \"jinx\" trying to use unequiped materias on \"vayne\" " << std::endl;
            jinx->unequip(0);
            jinx->use(0, *vayne);

        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "9. New character \"orianna\" equipping and unequipping materias" << std::endl;
            ICharacter* orianna = new Character("orianna");
            AMateria *cure = new Cure;
            AMateria *ice = new Ice;

            orianna->equip(cure);
            orianna->equip(ice);
            orianna->equip(cure);
            orianna->equip(ice);
            orianna->unequip(0);
            orianna->unequip(1);
            orianna->unequip(2);
            orianna->unequip(3);
            orianna->equip(cure);
            orianna->equip(ice);

            orianna->printMaterias();

        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //

        std::cout << "10. Testing if unequiped materia is freed" << std::endl;

            ICharacter* test = new Character("test");
            
            test->equip(src->createMateria("ice"));
            test->unequip(0);

        std::cout << std::endl;

    // ------------------------------------------------------------------------------------ //
        std::cout << "11. Deleting \"jinx\", \"vayne\", \"braum\" and \"orianna\"" << std::endl;
        
        delete test;
        delete orianna;
        delete braum;
        delete vayne;
        delete jinx;
        delete src;

        return (0);
    }
}
