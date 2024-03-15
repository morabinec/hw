#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct
{
  int m_TotalDays;
  int m_WorkDays;
} TResult;
#endif /* __PROGTEST__ */

void debug(TResult r)
{
  printf("TD: %i\nWD: %i\n", r.m_TotalDays, r.m_WorkDays);
}


bool isLeapYear (int y) //pomocna funkce na zjisteni prestupneho roku
{
  if ((y % 4 == 0 || y % 400 == 0) && (y % 100 != 0 || y % 4000 != 0)) 
    return true;
  
  return false;
}

bool isValidDate (int y, int m, int d)
{
  if (y >= 2000 && (m >= 1 && m <= 12) && (d >= 1 && d <= 31)) 
    return true;
  
  return false;
}

//Zellers algorithm
//source: https://cs.wikipedia.org/wiki/Algoritmus_pro_výpočet_dne_v_týdnu
bool isWeekend ( int y, int m, int d ) {

  int q = d;
  int K = y % 100;
  int J = y / 100;

  if (m < 3) {
    m += 12;
    K -= 1;
    if (K == -1) {
        K = 99;
        J = 99;
    }
    }

  int h = (q + (13 * (m + 1) / 5) + K + (K / 4) + (J / 4) + 5 * J) % 7;  
  
  if (h < 2)
    return true;
  else
    return false;
}

bool isHoliday(int m, int d)
{
  int holidayMonths[] = {1, 5, 5, 7, 7, 9, 10, 11, 12, 12, 12};
  int holidayDays[] = {1, 1, 8, 5, 6, 28, 28, 17, 24, 25, 26};

  for (int i = 0; i < 11; i++) {
    if ( m == holidayMonths[i] && d == holidayDays[i] )
      return true;
  }
  return false;
}

int maxDaysInMonth (int y, int m, int d )
{

  int maxDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(isLeapYear(y) && m == 2) 
    maxDays[1] = 29;
  else
    maxDays[1] = 28;

  return maxDays[m-1]; 
    
}

bool isWorkDay ( int y, int m, int d )
{
  /* todo */
  if (!isValidDate( y, m, d ))
    return false;

  if (d > maxDaysInMonth( y, m, d ))
    return false;

  if (isHoliday( m, d ) || isWeekend( y, m, d )) {
    return false;
  }

  return true;

}

TResult countDays ( int y1, int m1, int d1,
                    int y2, int m2, int d2 )
{
  /* todo */

  TResult r;
  r.m_TotalDays = 0;
  r.m_WorkDays = 0;


  while (1) {

    if (y1 > y2 || (y1 == y2 && (m1 > m2 || (m1 == m2 && d1 > d2))) || !isValidDate(y1, m1, d1) || !isValidDate(y2, m2, d2) || !maxDaysInMonth(y1, m1, d1) || !maxDaysInMonth(y2, m2, d2)) {
    r.m_TotalDays = -1;
    r.m_WorkDays = -1;
    return r;
  }

    r.m_TotalDays++;

    if (isWorkDay(y1, m1, d1)) {
      r.m_WorkDays++;
    }

    if( y1 == y2 && m1 == m2 && d1 == d2)
        break;

    d1++;

    if (d1 > maxDaysInMonth(y1, m1, d1)) {
        d1 = 1;
        m1++;
    }

    if (m1 > 12) {
        m1 = 1;
        y1++;
    }
  
}

  return r;
  
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TResult r;
  

  assert ( isWorkDay ( 2023, 10, 10 ) );

  assert ( ! isWorkDay ( 2023, 11, 11 ) );

  assert ( ! isWorkDay ( 2023, 11, 17 ) );

  assert ( ! isWorkDay ( 2023, 11, 31 ) );

  assert ( ! isWorkDay ( 2023,  2, 29 ) );

  assert ( ! isWorkDay ( 2004,  2, 29 ) );

  assert ( isWorkDay ( 2008,  2, 29 ) );

  assert ( ! isWorkDay ( 2001,  2, 29 ) );

  assert ( ! isWorkDay ( 1996,  1,  2 ) );

  //debug(r);


  r = countDays ( 2023, 11,  1,
                  2023, 11, 30 );
  assert ( r . m_TotalDays == 30 );
  assert ( r . m_WorkDays == 21 );

  r = countDays ( 2023, 11,  1,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 17 );
  assert ( r . m_WorkDays == 12 );

  r = countDays ( 2023, 11,  1,
                  2023, 11,  1 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 1 );

  r = countDays ( 2023, 11, 17,
                  2023, 11, 17 );
  assert ( r . m_TotalDays == 1 );
  assert ( r . m_WorkDays == 0 );

  r = countDays ( 2023,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 365 );
  assert ( r . m_WorkDays == 252 );

  r = countDays ( 2024,  1,  1,
                  2024, 12, 31 );
  assert ( r . m_TotalDays == 366 );
  assert ( r . m_WorkDays == 254 );

  
  r = countDays ( 2000,  1,  1,
                  2023, 12, 31 );
  assert ( r . m_TotalDays == 8766 );
  assert ( r . m_WorkDays == 6072 ); 

  r = countDays ( 2001,  2,  3,
                  2023,  7, 18 );
  assert ( r . m_TotalDays == 8201 );
  assert ( r . m_WorkDays == 5682 );

  r = countDays ( 2021,  3, 31,
                  2023, 11, 12 );
  assert ( r . m_TotalDays == 957 );
  assert ( r . m_WorkDays == 666 );

  r = countDays ( 2001,  1,  1,
                  2000,  1,  1 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );

  r = countDays ( 2001,  1,  1,
                  2023,  2, 29 );
  assert ( r . m_TotalDays == -1 );
  assert ( r . m_WorkDays == -1 );

  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
