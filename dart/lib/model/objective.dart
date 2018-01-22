part of swagger.api;

@Entity()
class Objective {
  /* type of objective function, i.e. min or min-max  */
  @Property(name: 'type')
  String type = null;
  //enum typeEnum {  min,  min-max,  };
/* objective function value */
  @Property(name: 'value')
  String value = null;
  //enum valueEnum {  completion_time,  transport_time,  vehicles,  };
  Objective();

  @override
  String toString()  {
    return 'Objective[type=$type, value=$value, ]';
  }
}

