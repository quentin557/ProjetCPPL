#include "obersverpattern.h"

void Subject::notify() {
  // 5. Publisher broadcasts
  for (size_t i = 0; i < views.size(); i++)
    views[i]->update();
}
