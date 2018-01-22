part of swagger.api;

@Entity()
class Routing {
  /* indicates whether solution should come with route geometries */
  @Property(name: 'calc_points')
  bool calcPoints = null;
  
  Routing();

  @override
  String toString()  {
    return 'Routing[calcPoints=$calcPoints, ]';
  }
}

