/**
 * @author: Dipankar Das
 * @brief: Shortest Job first scheduling
 * @describe: from the current track no which is the next track
 * to move so that the no of tracks jumped are min
 *
 * @solution: create max and min heap
 * @pseduo: 
 *  if curr_track >= req_track:
 *    add to the max_heap() which is left
 *  else:
 *    add to the min_heap() which is right to it
 *  
 *  @logic
 *        MAX_HEAP       MIN_HEAP
 *          100              50
 *        /   \             /  \
 *      40    79          79   90
 *    here we choose which heap root node difference with curr_track is least
 *    we delete that node and heapify() that
 */
#include <stdio.h>
#include <stdlib.h>

struct disk {
  int track: 10;      // 1024 for no of tracks
  int sector: 8;      // 256 for no of sectors
  int cylinder: 3;    // 6 no of cylinders
};

#define HEAP_ARR_SIZE 100

struct diskScheduling {
  struct disk left_options[HEAP_ARR_SIZE];
  struct disk right_options[HEAP_ARR_SIZE];
  int leftHeapSize;
  int rightHeapSize;
  int currTrack: 10;
};


int main(int argc, char **argv) {


  remove(argv[0]);
  return EXIT_SUCCESS;
}

