// modern c++ calculator
#include <iostream>

enum Operation
{
    kAdd = 1,
    kSub,
    kMul,
    kDiv
};

template< typename T >
T evaluate( T a, T b, int operation ) noexcept( false );

template< typename T >
T sum( T a, T b ) noexcept;

template< typename T >
T subtraction( T a, T b ) noexcept;

template< typename T >
T multiplication( T a, T b ) noexcept;

template< typename T >
T division( T a, T b ) noexcept( false );

template< typename T >
T evaluate( const T a, const T b, const int operation ) noexcept( false )
{
    switch ( operation )
    {
        case kAdd:
            return sum( a, b );
        case kSub:
            return subtraction( a, b );
        case kMul:
            return multiplication( a, b );
        case kDiv:
            return division( a, b );
        default:
            throw( std::invalid_argument( "Invalid argument" ) );
    }
}

template< typename T >
T sum( const T a, const T b ) noexcept
{
    return a + b;
}

template< typename T >
T subtraction( const T a, const T b ) noexcept
{
    return a - b;
}

template< typename T >
T multiplication( const T a, const T b ) noexcept
{
    return a * b;
}

template< typename T >
T division( const T a, const T b ) noexcept( false )
{
    if ( b == 0 )
    {
        throw( std::runtime_error( "Can not be divided by zero" ) );
    }
    return a / b;
}
int main()
{
    double a, b, result;
    int choice;
    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;
    std::cout << "What u wanna do:\n";
    std::cout << kAdd << ".Sum\n"
              << kSub << ".Subtraction\n"
              << kMul << ".Multiplication\n"
              << kDiv << ".Division\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    try
    {
        result = evaluate( a, b, choice );
        std::cout << "Your result: " << result;
    }
    catch ( const std::exception& ex )
    {
        std::cerr << ex.what();
        return EXIT_FAILURE;
    }
}
