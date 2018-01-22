part of swagger.api;

@Entity()
class Configuration {
  
  @Property(name: 'routing')
  Routing routing = null;
  
  Configuration();

  @override
  String toString()  {
    return 'Configuration[routing=$routing, ]';
  }
}

