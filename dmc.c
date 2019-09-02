#include <stdio.h>
#include <stdlib.h>

#define MAXCACHELINES 256

/* miss penalty in cycles */
#define MISSPENALTY 100

void main(int argc, char* argv[]) {
  unsigned int tags[MAXCACHELINES];
  unsigned int addr;
  int i;
  int hit=0, miss=0, tag=0, index=0;
  float hitrate;
  int cycles=0;
  int linesize=0, cachelines=0;

  if (argc != 3) {
    fprintf(stderr, "usage: dmc linesize cachelines\n");
    exit(1);
  }
  linesize = atoi(argv[1]);
  cachelines = atoi(argv[2]);

  if (linesize < 4) {
    fprintf(stderr, "linesize should be >= 4\n");
    exit(1);
  }

  if (cachelines < 1) {
    fprintf(stderr, "cachelines should be >= 1\n");
    exit(1);
  }

  printf("linessize=%d cachelines=%d\n", linesize, cachelines);

  /* clear the tags */
  for(i=0; i<cachelines; i++) {
    tags[i] = 0;
  }

  /* read the addresses and simulate the cache */
  while(scanf("%x", &addr) > 0) {
    /* your code goes here */
    tag = (addr / linesize);
    index = tag % cachelines;
    if (tags[index] == tag) {
        cycles++;
        hit++;
    } else {
        tags[index] = tag;
        cycles = cycles + 100;
        miss++;
    }
  }

  hitrate= (float) hit/(hit+miss);

  printf("hits=%d misses=%d\n", hit, miss);
  printf("hitrate=%f\n", hitrate);
  printf("cycles=%d\n", cycles);
}
