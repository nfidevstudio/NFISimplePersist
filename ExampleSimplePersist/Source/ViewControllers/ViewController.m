//
//  ViewController.m
//  ExampleSimplePersist
//
//  Created by José Carlos on 15/2/16.
//  Copyright © 2016 José Carlos. All rights reserved.
//

#import "ViewController.h"
#import "User.h"
#import "NFISimplePersist.h"

@interface ViewController () <UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, weak) IBOutlet UITextField *keyField;
@property (nonatomic, strong) NSMutableArray *users;
@property (nonatomic, weak) IBOutlet UITableView *tableView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _users = [[[NFISimplePersist standarSimplePersist] loadAllObjectsWithClass:[User class]] mutableCopy];
    
    User *user1 = [[User alloc] initWithId:0 user:@"NFI" andPass:@"no-pass-2"];
    User *user2 = [[User alloc] initWithId:1 user:@"NFI" andPass:@"no-pass-3"];
    User *user3 = [[User alloc] initWithId:2 user:@"NFI" andPass:@"no-pass-4"];

    [[NFISimplePersist standarSimplePersist] saveObjects:[NSArray arrayWithObjects:user1, user2, user3, nil] withKey:@"pass" andCompletionBlock:^(BOOL success){
        NSLog(@"Completed");
        [self updateUsers];
    }];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)updateUsers {
    _users = [[[NFISimplePersist standarSimplePersist] loadAllObjectsWithClass:[User class]] mutableCopy];
    [_tableView reloadData];
}

#pragma mark - Actions

- (IBAction)addUser:(id)sender {
    User *user = [[User alloc] initWithId:_users.count user:@"NFI" andPass:@"no-pass"];
    [[NFISimplePersist standarSimplePersist] saveObject:user withKey:[NSString stringWithFormat:@"%ld",(long)user.id]];
    [self updateUsers];
}

- (IBAction)removeAllUsers:(id)sender {
    [[NFISimplePersist standarSimplePersist] removeAllObjects];
    [self updateUsers];
}

- (IBAction)removeUserWithKey:(id)sender {
    if (_keyField) {
        if (_keyField.text) {
            if (![_keyField.text isEqualToString:@""]) {
                if (![[NFISimplePersist standarSimplePersist] removeObjectWithKey:_keyField.text andClass:[User class]]) {
                    NSLog(@"Error");
                }
                [self updateUsers];
            }
        }
    }
}

#pragma mark - UITableViewDelegate

- (NSInteger)tableView:(UITableView *)tableView sectionForSectionIndexTitle:(NSString *)title atIndex:(NSInteger)index {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _users.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *simpleTableIdentifier = @"SimpleTableItem";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    
    User *user = [_users objectAtIndex:indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@: %d",user.user, user.id];
    return cell;
}

@end
