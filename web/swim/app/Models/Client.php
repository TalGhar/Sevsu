<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Client extends Model
{
    use HasFactory;

    protected $table = 'clients';

    protected $primaryKey = 'id';

    protected $fillable = [
        'name',
        'surname',
        'patron',
        'email',
        'password'
    ];

    public function orders()
    {
        return $this->hasMany('App\Models\Order');
    }
}
