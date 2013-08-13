/* Verify that we don't libcall for complex / real.  */
/* { dg-do compile } */
/* { dg-options "-std=c99 -O -fdump-tree-optimized" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */

typedef _Complex float C;

C foo(C x, float y)
{
  return x / y;
}

/* { dg-final { scan-tree-dump-times "__div" 0 "optimized" } } */
/* { dg-final { cleanup-tree-dump "optimized" } } */