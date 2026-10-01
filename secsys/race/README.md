Misc.
===

- Why spinlock_unsafe.c is unsafe

| Step | Process A                                  | Process B                                  |
| ---- | ------------------------------------------ | ------------------------------------------ |
| 1    | Reads `*lock == 1` and exits the loop        |                                            |
| 2    |                                            | Reads `*lock == 1` and exits the loop        |
| 3    | Writes `*lock = 0`; enters critical section |                                            |
| 4    |                                            | Writes `*lock = 0`; enters critical section |
