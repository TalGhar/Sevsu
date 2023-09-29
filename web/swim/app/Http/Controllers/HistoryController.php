<?php

namespace App\Http\Controllers;

use App\Models\History;
use Illuminate\Http\Request;

class HistoryController extends Controller
{
    public function store(Request $request)
    {
        $validated = $request->validate([
            'history_text' => 'required',
        ]);

        if (History::create($validated))
            return response()->json(['success' => true]);
        return response()->json(['success' => false, 'errors' => ['asd' => 'dsa']]);
    }

    public function receive()
    {
        $history = History::all();
        return $history;
    }

    public function edit(Request $request)
    {
        $history = History::find($request->id);
        $history->history_text = $request->text;
        $history->save();
        return response()->json(['success' => true]);
    }

    public function delete(Request $request)
    {
        $history = History::find($request->id);
        $history->delete();
    }
}
