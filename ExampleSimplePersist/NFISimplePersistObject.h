//
//  NFISimplePersistObject.h
//  ExampleSimplePersist
//
//  Created by José Carlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Response block for save object
 */
typedef void (^UploadObjectCompletionBlock)(BOOL success);

@protocol NFISimplePersistObject <NSObject>

@required

/**
 *  Implement in model class. Return a dictionary (key - value) with the properties of the class.
 */
- (NSDictionary *)saveAsDictionary;

/**
 *  Implement in model class. Return the object given a dictionary.
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

