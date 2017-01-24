#import "SWGGHGeocodingLocation.h"

@implementation SWGGHGeocodingLocation

- (instancetype)init {
  self = [super init];
  if (self) {
    // initialize property's default value, if any
    
  }
  return self;
}


/**
 * Maps json key to property name.
 * This method is used by `JSONModel`.
 */
+ (JSONKeyMapper *)keyMapper {
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"point": @"point", @"osmId": @"osm_id", @"osmType": @"osm_type", @"name": @"name", @"country": @"country", @"city": @"city", @"state": @"state", @"street": @"street", @"housenumber": @"housenumber", @"postcode": @"postcode" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"point", @"osmId", @"osmType", @"name", @"country", @"city", @"state", @"street", @"housenumber", @"postcode"];
  return [optionalProperties containsObject:propertyName];
}

@end
