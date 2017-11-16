int main()
{
  // Following two lines generate no code since have no effect
  // on function result - still returns 0
  int *p = new int(1000);
  delete p;
}
