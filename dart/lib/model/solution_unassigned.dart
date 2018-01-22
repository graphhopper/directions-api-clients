part of swagger.api;

@Entity()
class SolutionUnassigned {
  /* An array of ids of unassigned services */
  @Property(name: 'services')
  List<String> services = [];
  
/* An array of ids of unassigned shipments */
  @Property(name: 'shipments')
  List<String> shipments = [];
  
  SolutionUnassigned();

  @override
  String toString()  {
    return 'SolutionUnassigned[services=$services, shipments=$shipments, ]';
  }
}

