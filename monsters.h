// Monsters.h
#define LIST_OF_MONSTERS(X)                                                    \
  X(dwarf, 'h', 2, ATK_HIT, 0)                                                 \
  X(kobold, 'k', 2, ATK_HIT, IMM_POISON)                                       \
  X(elf, '@', 3, ATK_HIT, 0)                                                   \
  X(centipede, 'c', 3, ATK_BITE, 0)                                            \
  X(orc, 'o', 4, ATK_HIT, IMM_POISON)