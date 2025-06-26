/***************************************************************************
 *  @file       ex_06.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <iostream>
#include <stdexcept>

class exceptionType
{
};

typedef int EXCPTYPE;

int main()
{
    try
    {
        // (a) Throws pointer to exceptionType, caught by catch(exceptionType *pet)
        throw new exceptionType;

        // (b) Throws int, caught by catch(...)
        throw 42;

        // (c) Throws int, caught by catch(EXCPTYPE)
        throw 7;
    }
    catch (exceptionType *pet)
    {
        std::cout << "(a) Caught exceptionType pointer." << std::endl;
        delete pet;
    }
    catch (EXCPTYPE ex)
    {
        std::cout << "(c) Caught EXCPTYPE (int): " << ex << std::endl;
    }
    catch (...)
    {
        std::cout << "(b) Caught unknown exception." << std::endl;
    }

    return 0;
}
