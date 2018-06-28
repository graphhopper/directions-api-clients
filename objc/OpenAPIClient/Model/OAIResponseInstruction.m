#import "OAIResponseInstruction.h"

@implementation OAIResponseInstruction

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
  return [[JSONKeyMapper alloc] initWithModelToJSONDictionary:@{ @"text": @"text", @"streetName": @"street_name", @"distance": @"distance", @"time": @"time", @"interval": @"interval", @"sign": @"sign", @"annotationText": @"annotation_text", @"annotationImportance": @"annotation_importance", @"exitNumber": @"exit_number", @"turnAngle": @"turn_angle" }];
}

/**
 * Indicates whether the property with the given name is optional.
 * If `propertyName` is optional, then return `YES`, otherwise return `NO`.
 * This method is used by `JSONModel`.
 */
+ (BOOL)propertyIsOptional:(NSString *)propertyName {

  NSArray *optionalProperties = @[@"text", @"streetName", @"distance", @"time", @"interval", @"sign", @"annotationText", @"annotationImportance", @"exitNumber", @"turnAngle"];
  return [optionalProperties containsObject:propertyName];
}

@end
