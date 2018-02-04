// Customer.cpp
    #include <sstream>
    #include <vector>
    #include <string>
    #include "Customer.h"

    using std::ostringstream;
    using std::vector;

    std::string Customer::statement() {
     int frequentRenterPoints = 0;
     vector< Rental >::iterator iter = _rentals.begin();
     vector< Rental >::iterator iter_end = _rentals.end();
     ostringstream result;
     result << "Rental Record for " << getName() << "\n";
     for ( ; iter != iter_end; ++iter ) {
       Rental each = *iter;


          // show figures for this rental
          result << "\t" << each.getMovie().getTitle() << "\t"
                 << each.getCharge() << "\n";
        }
        // add footer lines
        result << "Amount owed is " << getTotalCharge() << "\n";
        result << "You earned " << getTotalFrequentRenterPoints()
               << " frequent renter points";
        return result.str();
      }

      int Customer::getTotalFrequentRenterPoints()
      {
        int result = 0;
        vector< Rental >::iterator iter = _rentals.begin();
        vector< Rental >::iterator iter_end = _rentals.end();
        for ( ; iter != iter_end; ++iter ) {
          Rental each = *iter;
          result += each.getFrequentRenterPoints();
        }
        return result;
      }

        double Customer::getTotalCharge()
        {
          double result = 0;
          vector< Rental >::iterator iter = _rentals.begin();
          vector< Rental >::iterator iter_end = _rentals.end();
          for ( ; iter != iter_end; ++iter ) {
            Rental each = *iter;
            result += each.getCharge();
          }
          return result;
        }
