<?php

class AuthModel extends Model {
    public function __construct() {
        parent::__construct();
        static::$tablename = 'users';
        static::$dbfields = array('fullname', 'email', 'username', 'password');
    }

    public function createUser($post_array) {
        
        $findUserByEmail = $this->findByField($post_array['email'], 'email');
        $findUserByLogin = $this->findByField($post_array['username'], 'username');
        
		if ($findUserByEmail != null || $findUserByLogin != null) {
            return false;
        }
        
        $data = [
			"fullname" => $post_array["fullname"],
			"email" => $post_array['email'],
			"login" => $post_array["username"],
			"password" => $post_array["password"]
        ];

        $this->save($data);
    }

    public function findUser($post_array) {
        $user = $this->findByQuery("`username`='".$post_array['username']."' AND `password`='".$post_array['password']."'");

		if ($user == null) {
			return false;
        }

        return $user;
    }
}