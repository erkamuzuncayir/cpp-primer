/***************************************************************************
 *  @file       ex_05.cpp
 *  @author     Erkam Uzuncayir
 *  @date       2025-05-26
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        // use of the C++ standard library
    }
    catch (const std::overflow_error &e)
    {
        std::cerr << "Overflow error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::underflow_error &e)
    {
        std::cerr << "Underflow error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::range_error &e)
    {
        std::cerr << "Range error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out-of-range error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::domain_error &e)
    {
        std::cerr << "Domain error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::length_error &e)
    {
        std::cerr << "Length error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::logic_error &e)
    {
        std::cerr << "Logic error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        std::abort();
    }
    catch (const std::exception &e)
    {
        std::cerr << "General exception: " << e.what() << std::endl;
        std::abort();
    }

    return 0;
}
